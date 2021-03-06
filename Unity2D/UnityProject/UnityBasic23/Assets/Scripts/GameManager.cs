using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public CameraTracker cameraTracker;
    public Responner responnerPlayer;
    public Responner responnerEagle;
    public Responner responnerOpposum;

    public ItemManager itemManager;

    public List<GameObject> listGUIScene;
    public enum E_GUI_STATE { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUI_STATE curGUIState;

    public GUIPlayerInfo guiPlayerInfo;

    public GameObject objPopupLayer;
    public GUIIventory guiIventory;
    public GUIItemPopup guiItemPopup;

    public void SetPopup()
    {
        if (objPopupLayer.activeSelf == false)
        {
            Time.timeScale = 0;
            objPopupLayer.SetActive(true);
            //if (responnerPlayer.objPlayer)
            //   guiIventory.SetIventory(responnerPlayer.objPlayer.GetComponent<Iventory>());
        }
        else
        {
            //guiIventory.RemoveButtons();
            objPopupLayer.SetActive(false);
            Time.timeScale = 1;
        }
        guiItemPopup.gameObject.SetActive(false);
    }

    public void UpdatePopup()
    {
        if (objPopupLayer.activeSelf == true)
        {
            Iventory iventory = responnerPlayer.objPlayer.GetComponent<Iventory>();
            if (iventory.itemInfos.Count != guiIventory.listItemButton.Count)
            {
                guiIventory.RemoveButtons();
                if (responnerPlayer.objPlayer)
                    guiIventory.SetIventory(iventory);
            }
        }
    }

    public void ShowSecene(E_GUI_STATE state)
    {
        for (int i = 0; i < listGUIScene.Count; i++)
        {
            if (i == (int)state)
                listGUIScene[i].SetActive(true);
            else
                listGUIScene[i].SetActive(false);
        }
    }
    public void SetGUIStatus(E_GUI_STATE state)
    {
        switch(state)
        {
            case E_GUI_STATE.TITLE:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.GAMEOVER:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.PLAY:
                Time.timeScale = 1;
                break;
        }
        ShowSecene(state);
        curGUIState = state;
    }

    public void UpdateGUIStatus()
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
                guiPlayerInfo.Set(responnerPlayer.objPlayer);
                EventGameOver();
                EventCameraTargetFixed();
                EventEaglePonstFixed();
                if(Input.GetKeyDown(KeyCode.I))
                {
                    SetPopup();
                }
                break;
        }
    }

    static GameManager instance;
    public static GameManager GetInstance() { return instance; }

    private void Awake()
    {
        instance = this;
        objPopupLayer.SetActive(false);
        
        SetGUIStatus(curGUIState);
    }

    // Update is called once per frame
    void Update()
    {
        UpdateGUIStatus();
        UpdatePopup();
    }

    public void EventGameOver()
    {
        if (responnerPlayer.objPlayer == null)
        {
            SetGUIStatus(E_GUI_STATE.GAMEOVER);
        }
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
