#pragma once
class CApp :
    public CWinApp
{
public:
    BOOL InitInstance();
};

class CMainWin :
    public CFrameWnd
{
public:
    CMainWin();
    DECLARE_MESSAGE_MAP()
    void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
    void OnClose();
    void OnTimer(UINT_PTR);
    void OnMouseMove(UINT, CPoint);
    void OnChar(UINT, UINT, UINT);
private:
    int timer;
};

