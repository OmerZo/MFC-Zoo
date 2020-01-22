
// zooTestOneDlg.h : header file
//

#pragma once


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
public:
	CButton m_fish;
	CButton m_dog;
	CButton m_siami;
	CButton m_street;
	CListCtrl m_listCtrl;
	int m_type;
	void initItems();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnAdd();
	CEdit m_name;
	int m_age;
	afx_msg void OnBnClickedButton1();
};
