using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemButton : MonoBehaviour
{
    public Image imgIcon;
    public Text textName;
    public Button button;

    public void Set(ItemInfo itemInfo)
    {
        //if (imgIcon.sprite) Destroy(imgIcon.sprite);
        Sprite sprite = Resources.Load<Sprite>("icon/" + itemInfo.icon);
        imgIcon.sprite = sprite;
        textName.text = itemInfo.name;
        this.gameObject.name = itemInfo.name;
        
        button.onClick.AddListener(() => EventClick(itemInfo));
    }

    public void EventClick(ItemInfo itemInfo)
    {
        GameObject objPlayer = GameManager.GetInstance().responnerPlayer.objPlayer;
        Item.Use(itemInfo.effectMode, objPlayer);
    }

    ////테스트용 코드
    //public Item.E_ITEM_EFFECT itemeffect;
    //private void Start()
    //{
    //    Set(GameManager.GetInstance().itemManager.GetItemInfo(itemeffect));
    //}
}
