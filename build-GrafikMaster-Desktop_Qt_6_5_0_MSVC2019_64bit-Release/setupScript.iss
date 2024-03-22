; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Grafik Master"
#define MyAppVersion "1.0"
#define MyAppPublisher "Mateusz Marzec SoftTech"
#define MyAppURL "https://sawannaniz.net/"
#define MyAppExeName "GrafikMaster.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{FFA396DF-8F39-4935-94BA-6571FDBF7DBB}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
LicenseFile=C:\Users\marze\source\GrafikMaster\build-GrafikMaster-Desktop_Qt_6_5_0_MSVC2019_64bit-Release\release\LICENSE.txt
InfoAfterFile=C:\Users\marze\source\GrafikMaster\build-GrafikMaster-Desktop_Qt_6_5_0_MSVC2019_64bit-Release\release\README.txt
; Remove the following line to run in administrative install mode (install for all users.)
PrivilegesRequired=lowest
OutputDir=C:\Users\marze\source\GrafikMaster\build-GrafikMaster-Desktop_Qt_6_5_0_MSVC2019_64bit-Release
OutputBaseFilename=Grafik Master Setup
SetupIconFile=C:\Users\marze\source\GrafikMaster\build-GrafikMaster-Desktop_Qt_6_5_0_MSVC2019_64bit-Release\icon.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "polish"; MessagesFile: "compiler:Languages\Polish.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\marze\source\GrafikMaster\build-GrafikMaster-Desktop_Qt_6_5_0_MSVC2019_64bit-Release\release\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\marze\source\GrafikMaster\build-GrafikMaster-Desktop_Qt_6_5_0_MSVC2019_64bit-Release\release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
