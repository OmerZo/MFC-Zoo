
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

using namespace std;



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
	DDX_Control(pDX, IDC_BTN_UNDO, m_undo);
	DDX_Control(pDX, IDC_BTN_REDO, m_redo);
	DDX_Control(pDX, IDC_BTN_SAVE, m_save);
}

BEGIN_MESSAGE_MAP(CzooTestOneDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DEL, &CzooTestOneDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_ADD, &CzooTestOneDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_UNDO, &CzooTestOneDlg::OnBnClickedBtnUndo)
	ON_BN_CLICKED(IDC_BTN_REDO, &CzooTestOneDlg::OnBnClickedBtnRedo)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CzooTestOneDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CzooTestOneDlg::OnBnClickedBtnOpen)
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

	initList();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

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

HCURSOR CzooTestOneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CzooTestOneDlg::initList()
{
	m_listCtrl.InsertColumn(0, L"Name", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(1, L"Type", LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(2, L"Age", LVCFMT_LEFT, 70);
	m_listCtrl.InsertColumn(3, L"Number of legs", LVCFMT_LEFT, 150);
	m_listCtrl.InsertColumn(4, L"Sound", LVCFMT_LEFT, 80);
	m_listCtrl.InsertColumn(5, L"Color", LVCFMT_LEFT, 80);
}

void CzooTestOneDlg::OnBnClickedBtnDel()
{
	for (int nItem = 0; nItem < m_listCtrl.GetItemCount(); ) // delete selected item(s) 
	{
		if (m_listCtrl.GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
		{
			m_listCtrl.DeleteItem(nItem);
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

	m_name.GetWindowTextW(name);
	age.Format(_T("%d"), m_age);
	if (name.GetLength() > 0)
	{
		Animal* animal = createAnimal(name, age);
		insertAnimal(animal);

		done.push_back(animal);
		m_undo.EnableWindow(true);
		m_save.EnableWindow(true);
		undone.clear();
		m_redo.EnableWindow(false);

	}
	else
	{
		MessageBox(_T("Enter name!"), _T("Error"));
	}
}

void CzooTestOneDlg::OnBnClickedBtnUndo()
{
	if (m_listCtrl.GetItemCount() > 0)
	{
		undone.push_back(done.back());
		done.pop_back();
		m_listCtrl.DeleteItem(0);
		m_redo.EnableWindow(true);
	}

	if (m_listCtrl.GetItemCount() == 0)
	{
		m_undo.EnableWindow(false);
		m_save.EnableWindow(false);
	}
}

void CzooTestOneDlg::OnBnClickedBtnRedo()
{
	if (!undone.empty())
	{
		Animal *animal = undone.back();
		insertAnimal(animal);
		done.push_back(animal);
		undone.pop_back();
		m_undo.EnableWindow(true);
		m_save.EnableWindow(true);
	}

	if (undone.empty())
		m_redo.EnableWindow(false);
}

void CzooTestOneDlg::OnBnClickedBtnSave()
{
	char strFilter[] = { "Data Files (*.dat)" };
	CFileDialog saveDlg(false, _T("dat"), NULL, 0, CString(strFilter));
	if (saveDlg.DoModal() == IDOK)
	{
		CString s = saveDlg.GetPathName();
		CFile file(s, CFile::modeCreate | CFile::modeWrite);
		CArchive archive(&file, CArchive::store);

		int size = done.size();
		archive << size;

		for (vector<Animal*>::iterator it = done.begin(); it != done.end(); it++)
			(*it)->Serialize(archive);

		archive.Close();
		file.Close();
	}
}

void CzooTestOneDlg::OnBnClickedBtnOpen()
{
	CFileDialog openDlg(true, _T(".dat"));
	if (openDlg.DoModal() == IDOK)
	{
		CString s = openDlg.GetPathName();
		CFile file(s, CFile::modeRead);
		CArchive archive(&file, CArchive::load);
		done.clear();
		undone.clear();
		recreate(archive);
		archive.Close();
		file.Close();
	}
}

void CzooTestOneDlg::recreate(CArchive& archive)
{
	int size;
	CString type;
	CString color;
	CString age;
	CString name;
	Animal* animal = nullptr;

	m_listCtrl.DeleteAllItems();
	archive >> size;

	for (int i = 0; i < size; i++)
	{
		archive >> type;
		archive >> color;
		archive >> age;
		archive >> name;

		if (type.CompareNoCase(_T("Fish")))
			animal = new Fish(name, _T("Gold"), age);
		else if (type.CompareNoCase(_T("Dog")))
			animal = new Dog(name, _T("Brown"), age);
		else if (type.CompareNoCase(_T("Siami Cat")))
			animal = new SiamiC(name, _T("White"), age);
		else
			animal = new StreetC(name, _T("Black"), age);

		insertAnimal(animal);

		done.push_back(animal);
		m_undo.EnableWindow(true);
		m_save.EnableWindow(true);
		undone.clear();
		m_redo.EnableWindow(false);
	}
}

Animal* CzooTestOneDlg::createAnimal(CString name, CString age)
{
	Animal* animal = nullptr;
	switch (m_type)
	{
	case 0:
		animal = new Fish(name, _T("Gold"), age);
		break;
	case 1:
		animal = new Dog(name, _T("Brown"), age);
		break;
	case 2:
		animal = new SiamiC(name, _T("White"), age);
		break;
	case 3:
		animal = new StreetC(name, _T("Black"), age);
		break;
	default:
		break;
	}
	return animal;
}

void CzooTestOneDlg::insertAnimal(Animal* animal)
{
	int nItem;
	nItem = m_listCtrl.InsertItem(0, animal->getName());
	m_listCtrl.SetItemText(nItem, 1, animal->getType());
	m_listCtrl.SetItemText(nItem, 2, animal->getAge());
	m_listCtrl.SetItemText(nItem, 3, animal->getNumOfLegs());
	m_listCtrl.SetItemText(nItem, 4, animal->getSound());
	m_listCtrl.SetItemText(nItem, 5, animal->getColor());
}
