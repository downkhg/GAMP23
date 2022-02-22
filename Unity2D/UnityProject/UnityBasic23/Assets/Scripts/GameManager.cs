using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public CameraTracker cameraTracker;
    public Responner responnerPlayer;
    public Responner responnerEagle;
    public Responner responnerOpposum;

    public List<GameObject> listGUIScene;
    public enum E_GUI_STATE { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUI_STATE curGUIState;

    void ShowSecene(E_GUI_STATE state)
    {
        for (int i = 0; i < listGUIScene.Count; i++)
        {
            if (i == (int)state)
                listGUIScene[i].SetActive(true);
            else
                listGUIScene[i].SetActive(false);
        }
    }
    void SetGUIStatus(E_GUI_STATE state)
    {
        switch(state)
        {
            case E_GUI_STATE.TITLE:
                break;
            case E_GUI_STATE.THEEND:
                break;
            case E_GUI_STATE.GAMEOVER:
                break;
            case E_GUI_STATE.PLAY:
                break;
        }
        ShowSecene(state);
        curGUIState = state;
    }

    void UpdateGUIStatus()
    {
        switch (curGUIState)
        {
            case E_GUI_STATE.TITLE:
                break;
            case E_GUI_STATE.THEEND:
                break;
            case E_GUI_STATE.GAMEOVER:
                break;
            case E_GUI_STATE.PLAY:
                break;
        }
    }

    static GameManager instance;
    public static GameManager GetInstance() { return instance; }

    private void Awake()
    {
        instance = this;
        SetGUIStatus(curGUIState);
    }

    // Update is called once per frame
    void Update()
    {
        EventCameraTargetFixed();
        EventEaglePonstFixed();
        UpdateGUIStatus();
    }

    public void EventGUISceneChage(int idx)
    {
        SetGUIStatus((E_GUI_STATE)idx);
    }

    public void EventCameraTargetFixed()
    {
        if (responnerPlayer.objPlayer)
        {
            cameraTracker.objTarget = responnerPlayer.objPlayer;
        }
    }

    public  void EventEaglePonstFixed()
    {
        if (responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();
            if (eagle)
            {
                eagle.objResponPoint = responnerEagle.gameObject;
                eagle.objPatrolPoint = responnerOpposum.gameObject;
            }
        }
    }
}
