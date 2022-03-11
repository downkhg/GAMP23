using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class GUIItemButton : MonoBehaviour,IPointerExitHandler,IPointerEnterHandler
{
    public Image imgIcon;
    public Text textName;
    public Button button;
    public ItemInfo ItemInfo;

    public void Set(ItemInfo itemInfo)
    {
        //if (imgIcon.sprite) Destroy(imgIcon.sprite);
        Sprite sprite = Resources.Load<Sprite>("icon/" + itemInfo.icon);
        imgIcon.sprite = sprite;
        textName.text = itemInfo.name;
        this.gameObject.name = itemInfo.name;
        this.ItemInfo = itemInfo;
        button.onClick.AddListener(() => EventClick(itemInfo));
    }

    public void EventClick(ItemInfo itemInfo)
    {
        GameObject objPlayer = GameManager.GetInstance().responnerPlayer.objPlayer;
        if (Item.Use(itemInfo.effectMode, objPlayer))
            objPlayer.GetComponent<Iventory>().RemoveItemInfo(itemInfo);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        Debug.Log("GUIItemButton::OnPointerExit");
        GameManager.GetInstance().guiItemPopup.gameObject.SetActive(false);
        //((IPointerExitHandler)button).OnPointerExit(eventData);
    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        Debug.Log("GUIItemButton::OnPointerEnter");
        GameManager.GetInstance().guiItemPopup.gameObject.SetActive(true);
        GameManager.GetInstance().guiItemPopup.Set(ItemInfo);
    }

    ////테스트용 코드
    //public Item.E_ITEM_EFFECT itemeffect;
    //private void Start()
    //{
    //    Set(GameManager.GetInstance().itemManager.GetItemInfo(itemeffect));
    //}
}
