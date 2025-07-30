
// DefenderToggleAppDemoDlg.h : header file
//

#pragma once


// CDefenderToggleAppDemoDlg dialog
class CDefenderToggleAppDemoDlg : public CDialogEx
{
// Construction
public:
	CDefenderToggleAppDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEFENDERTOGGLEAPPDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton ChkEnableDefender;
	BOOL RunPowerShellCommand(const CString& command);
	afx_msg void OnBnClickedCheckEnabledefender();
};
---------------------------------------------------------------------------


// DefenderToggleAppDemoDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DefenderToggleAppDemo.h"
#include "DefenderToggleAppDemoDlg.h"
#include "afxdialogex.h"
#include<string> 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
bool IsRealtimeProtectionEnabled();
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDefenderToggleAppDemoDlg dialog



CDefenderToggleAppDemoDlg::CDefenderToggleAppDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEFENDERTOGGLEAPPDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDefenderToggleAppDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_EnableDefender, ChkEnableDefender);
}

BEGIN_MESSAGE_MAP(CDefenderToggleAppDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_EnableDefender, &CDefenderToggleAppDemoDlg::OnBnClickedCheckEnabledefender)
END_MESSAGE_MAP()


// CDefenderToggleAppDemoDlg message handlers

BOOL CDefenderToggleAppDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	BOOL isEnabled = IsRealtimeProtectionEnabled();
	ChkEnableDefender.SetCheck(isEnabled ? BST_CHECKED : BST_UNCHECKED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDefenderToggleAppDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDefenderToggleAppDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDefenderToggleAppDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
bool IsRealtimeProtectionEnabled()
{
	FILE* pipe = _popen("powershell -Command \"(Get-MpPreference).DisableRealtimeMonitoring\"", "r");
	if (!pipe) return false;

	char buffer[128];
	std::string result = "";

	while (fgets(buffer, sizeof(buffer), pipe) != NULL)
		result += buffer;

	_pclose(pipe);

	// If output is "True" → Realtime Monitoring is DISABLED
	// If output is "False" → Realtime Monitoring is ENABLED
	return (result.find("False") != std::string::npos);
}


bool IsRunningAsAdmin()
{
	BOOL isAdmin = FALSE;
	PSID adminGroup = nullptr;
	SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

	if (AllocateAndInitializeSid(
		&ntAuthority, 2,
		SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&adminGroup))
	{
		CheckTokenMembership(NULL, adminGroup, &isAdmin);
		FreeSid(adminGroup);
	}

	return isAdmin;
}
bool ToggleDefender(bool disable)
{
	const char* cmdEnable = "powershell -Command \"Set-MpPreference -DisableRealtimeMonitoring $false\"";
	const char* cmdDisable = "powershell -Command \"Set-MpPreference -DisableRealtimeMonitoring $true\"";

	int result = system(disable ? cmdDisable : cmdEnable);
	return result == 0;
}

void CDefenderToggleAppDemoDlg::OnBnClickedCheckEnabledefender()
{
	if (!IsRunningAsAdmin())
	{
		AfxMessageBox(_T("❌ Please run this program as Administrator."));
		return;
	}

	BOOL isChecked = IsDlgButtonChecked(IDC_CHECK_EnableDefender);
	bool success = ToggleDefender(!isChecked); // !isChecked because: checked = enable

	if (!success)
	{
		AfxMessageBox(_T("⚠️ Failed to change Real-Time Protection setting."));
	}
	
}

void CDefenderToggleAppDemoDlg::OnBnClickedOk()
{
	ShellExecute(
    NULL,
    _T("runas"),
    _T("cmd.exe"),
    NULL,
    NULL,
    SW_SHOWMINIMIZED
);

}
