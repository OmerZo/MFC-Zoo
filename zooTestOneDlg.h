
// zooTestOneDlg.h : header file
//

#pragma once
#include <vector>
#include "Animal.h"
using namespace std;


// CzooTestOneDlg dialog
class CzooTestOneDlg : public CDialogEx
{
// Construction
public:
	CzooTestOneDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZOOTESTONE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	vector<Animal*> done;
	vector<Animal*> undone;


public:
	CButton m_fish;
	CButton m_dog;
	CButton m_siami;
	CButton m_street;
	CListCtrl m_listCtrl;
	int m_type;
	int m_age;
	void initList();
	void recreate(CArchive & archive);
	Animal* createAnimal(CString name, CString age);
	void insertAnimal(Animal* animal);
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnAdd();
	CEdit m_name;
	afx_msg void OnBnClickedBtnUndo();
	CButton m_undo;
	afx_msg void OnBnClickedBtnRedo();
	CButton m_redo;
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnOpen();
	CButton m_save;
};
