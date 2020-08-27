import os;

signFailedCount=0
signSuccessCount=0

def msbuild():
    buildCmd = "\"C:/Program Files (x86)/MSBuild/14.0/Bin/MSBuild.exe\""\
        " " + os.getcwd() + "/systemhelp.sln"\
            " /m /t:Rebuild /p:Configuration=Release"
    print(buildCmd);
    buildCode = os.system(buildCmd)
    print("build obs-studio.sln result:" + ("success" if buildCode == 0 else "failed"))


    return True if buildCode == 0 else False
    
def test():
    p = "test"
    print(p)
    
def scanPath(fileDir, suffixs, option):
    global signFailedCount, signSuccessCount
    for fileName in os.listdir(fileDir):   ##遍历子目录
        if os.path.isdir((fileDir + "/" + fileName)):
            scanPath(fileDir + "/" + fileName, suffixs, option)
        else:
            for suffix in suffixs:
                if fileName.endswith(suffix):
                    if (option == "sign"):
                        if signFile(fileDir, fileName) == False:
                            signFailedCount += 1
                        else:
                            signSuccessCount += 1
                    #elif (option == "move"):

def signFile(fileDir, fileName):
    print("*************************sign begin:" + fileName + "*************************")

    result = True
    verifyCmd = "signtool.exe verify /pa /q " + fileDir + "/" + fileName
    verifyCode = os.system(verifyCmd)
    if verifyCode != 0:
        addVerCmd = os.getcwd() + "/resource_hacker/ResourceHacker.exe -open "\
            "" + fileDir + "/" + fileName + " -save "\
            "" + fileDir + "/" + fileName + \
            " -action addoverwrite -resource ./Resources.res"
        addVerCode = os.system(addVerCmd)
        print("addVersion result:" + ("success" if addVerCode == 0 else "failed"))
        if addVerCode == 0:
            signCmd = "signtool.exe sign /f xike.pfx /p Baidu@2022 /t http://timestamp.digicert.com " + fileDir + "/" + fileName
            signCode = os.system(signCmd)
            result = True if signCode == 0 else False
            print("signing result:" + ("success" if signCode == 0 else "failed"))
        else:
            result = False

    print("*************************sign end:" + fileName + "*************************\n\n")

    return result
    
def signFileAnyway(fileDir,fileName):

    addVerCmd = os.getcwd() + "/resource_hacker/ResourceHacker.exe -open "\
        "" + fileDir + "/" + fileName + " -save "\
        "" + fileDir + "/" + fileName + \
        " -action addoverwrite -resource ./Resources.res"
    addVerCode = os.system(addVerCmd)
    print("addVersion result:" + ("success" if addVerCode == 0 else "failed"))
        
    print("*************************sign begin:" + fileName + "*************************")
    signCmd = "signtool.exe sign /f xike.pfx /p Baidu@2022 /t http://timestamp.digicert.com " + fileDir + "/" + fileName
    signCode = os.system(signCmd)
    result = True if signCode == 0 else False
    print("signing result:" + ("success" if signCode == 0 else "failed"))
    print("*************************sign end:" + fileName + "*************************")
    
def signFiles(fileDir, suffixs):
    global signFailedCount, signSuccessCount
    signFailedCount = 0
    signSuccessCount = 0
    scanPath(fileDir, suffixs, "sign")
    print("\nsign with " + str(signFailedCount) + " failed, " + str(signSuccessCount) + " success\n")
    return True if signFailedCount == 0 else False
    
def generageRcFile():
    rcContent = \
        "VS_VERSION_INFO VERSIONINFO\n"\
            "    FILEVERSION    1,0,0,0\n"\
            "    PRODUCTVERSION 2,0,0,0\n"\
            "{\n"\
            "    BLOCK \"StringFileInfo\"\n"\
            "    {\n"\
            "        BLOCK \"080404b0\"\n"\
            "        {\n"\
            "            VALUE \"CompanyName\", \"systemhelp1\"\n"\
            "            VALUE \"FileDescription\", \"systemhelp2 cmd\"\n"\
            "            VALUE \"FileVersion\", \"1.0.0.0\"\n"\
            "            VALUE \"InternalName\", \"systemhelp3\"\n"\
            "            VALUE \"LegalCopyright\", \"Copyright (C) 2019\"\n"\
            "            VALUE \"OriginalFilename\", \"systemhelp4\"\n"\
            "            VALUE \"ProductName\", \"systemhelp5 ui\"\n"\
            "            VALUE \"ProductVersion\", \"2.0.0.0\"\n"\
            "        }\n"\
            "    }\n"\
            "    BLOCK \"VarFileInfo\"\n"\
            "    {\n"\
            "        VALUE \"Translation\", 0x804, 1200\n"\
            "    }\n"\
            "}"

    with open(os.getcwd() + "/Resources.rc", "w") as rcFile:
        rcFile.write(rcContent)

def generageResFile():
    cmd = os.getcwd() + "/resource_hacker/ResourceHacker.exe -open ./Resources.rc -save ./Resources.res -action compile"
    code = os.system(cmd)
    print("generageResFile result:" + ("success!" if code == 0 else "failed!"))
    
def SignFiles():
    signFiles(os.getcwd() + "/Release", [".dll", ".exe"])
 
def buildSetup():
    generageRcFile()
    generageResFile()
    SignFiles()
 
if __name__ == '__main__':
    buildSetup()
    os.system("pause")