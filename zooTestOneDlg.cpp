
// zooTestOneDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "zooTestOne.h"
#include "zooTestOneDlg.h"
#include "afxdialogex.h"
#include "Animal.h"
#include "Fish.h"
#include "Dog.h"
#include "Cat.h"
#include "SiamiC.h"
#include "StreetC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzooTestOneDlg dialog



CzooTestOneDlg::CzooTestOneDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ZOOTESTONE_DIALOG, pParent)
	, m_type(0)
	, m_age(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CzooTestOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Fish, m_fish);
	DDX_Control(pDX, IDC_ANIMAL_LIST, m_listCtrl);
	DDX_Control(pDX, IDC_DOG, m_dog);
	DDX_Control(pDX, IDC_SIAMI_C, m_siami);
	DDX_Control(pDX, IDC_STREET_C, m_street);
	DDX_Radio(pDX, IDC_Fish, m_type);
	DDX_Control(pDX, IDC_ED_NAME, m_name);
	DDX_Text(pDX, IDC_ED_AGE, m_age);
	DDV_MinMaxInt(pDX, m_age, 0, 9999);
}

BEGIN_MESSAGE_MAP(CzooTestOneDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DEL, &CzooTestOneDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_ADD, &CzooTestOneDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BUTTON1, &CzooTestOneDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CzooTestOneDlg message handlers

BOOL CzooTestOneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	initItems();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CzooTestOneDlg::OnPaint()
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
HCURSOR CzooTestOneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CzooTestOneDlg::initItems()
{
	m_listCtrl.InsertColumn(0, L"Name", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(1, L"Type", LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(2, L"Age", LVCFMT_LEFT, 70);
	m_listCtrl.InsertColumn(3, L"Number of legs", LVCFMT_LEFT, 150);
	m_listCtrl.InsertColumn(4, L"Sound", LVCFMT_LEFT, 80);
	m_listCtrl.InsertColumn(5, L"Color", LVCFMT_LEFT, 80);

	//int nItem;

	//nItem = m_listCtrl.InsertItem(0, L"Mark");
	//m_listCtrl.SetItemText(nItem, 1, L"Siami Cat");
	//m_listCtrl.SetItemText(nItem, 2, L"45");
	//m_listCtrl.SetItemText(nItem, 3, L"4");
	//m_listCtrl.SetItemText(nItem, 4, L"mio");
	//m_listCtrl.SetItemText(nItem, 5, L"Black");

	//nItem = m_listCtrl.InsertItem(0, L"Allan");
	//m_listCtrl.SetItemText(nItem, 1, L"Dog");
	//m_listCtrl.SetItemText(nItem, 2, L"28");
	//m_listCtrl.SetItemText(nItem, 3, L"4");
	//m_listCtrl.SetItemText(nItem, 4, L"wof");
	//m_listCtrl.SetItemText(nItem, 5, L"Brown");

	//nItem = m_listCtrl.InsertItem(0, L"Ajay");
	//m_listCtrl.SetItemText(nItem, 1, L"Fish");
	//m_listCtrl.SetItemText(nItem, 2, L"2");
	//m_listCtrl.SetItemText(nItem, 3, L"0");
	//m_listCtrl.SetItemText(nItem, 4, L"blo");
	//m_listCtrl.SetItemText(nItem, 5, L"yellow");
}

void CzooTestOneDlg::OnBnClickedBtnDel()
{
	for (int nItem = 0; nItem < m_listCtrl.GetItemCount(); ) // delete selected item(s) 
	{
		if (m_listCtrl.GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
		{
			m_listCtrl.DeleteItem(nItem);
			//CmySecondAppDlg::nId--;
		}
		else
			++nItem;
	}
}

void CzooTestOneDlg::OnBnClickedBtnAdd()
{
	UpdateData();

	CString name = _T("");
	CString age = _T("");
	CString type = _T("");
	int nItem;

	m_name.GetWindowTextW(name);
	age.Format(_T("%d"), m_age);
	if (name.GetLength() > 0)
	{
		Animal* animal = nullptr;
		switch (m_type)
		{
		case 0:
			animal = new Fish(name, _T("Gold"), age);
			type = _T("Fish");
			break;
		case 1:
			animal = new Dog(name, _T("Brown"), age);
			type = _T("Dog");
			break;
		case 2:
			animal = new SiamiC(name, _T("White"), age);
			type = _T("Siami Cat");
			break;
		case 3:
			animal = new StreetC(name, _T("Black"), age);
			type = _T("Street Cat");
			break;
		default:
			break;
		}

		nItem = m_listCtrl.InsertItem(0, animal->getName());
		m_listCtrl.SetItemText(nItem, 1, type);
		m_listCtrl.SetItemText(nItem, 2, animal->getAge());
		m_listCtrl.SetItemText(nItem, 3, animal->getNumOfLegs());
		m_listCtrl.SetItemText(nItem, 4, animal->getSound());
		m_listCtrl.SetItemText(nItem, 5, animal->getColor());
	}
	else
	{
		MessageBox(_T("Enter name!"), _T("Error"));
	}
}


void CzooTestOneDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}
