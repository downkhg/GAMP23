using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIStatusBar : MonoBehaviour
{
    public RectTransform recttrStatusBar;
    public RectTransform recttrStatusBarBG;
    public void SetStatus(float cur, float max)
    {
        float rat = cur / max;
        Vector2 vSize = recttrStatusBar.sizeDelta;
        vSize.x = recttrStatusBarBG.sizeDelta.x * rat;
        recttrStatusBar.sizeDelta = vSize;
        //구조체는 값이 복사되므로 원본에 접근이 불가능하기때문에 직접엑세스를 통한 수정이 불가능하다.
        //recttrStatusBar.sizeDelta.x = recttrStatusBarBG.sizeDelta.x * rat;
    }
}
