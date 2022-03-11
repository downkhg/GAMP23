using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Iventory : MonoBehaviour
{
    public List<ItemInfo> itemInfos;

    public void SetInventory(Item item)
    {
        if(item)
        {
            ItemInfo itemInfo = GameManager.GetInstance().itemManager.GetItemInfo(item.eEffect);
            itemInfos.Add(itemInfo);
        }
    }

    public void SetInventory(Item.E_ITEM_EFFECT item_eff)
    {
        ItemInfo itemInfo = GameManager.GetInstance().itemManager.GetItemInfo(item_eff);
        itemInfos.Add(itemInfo);
    }

    public ItemInfo GetItemInfo(Item item)
    {
        if(item)
        {
            return itemInfos.Find(iteminfo => item.eEffect == iteminfo.effectMode);
        }
        return null;
    }

    public ItemInfo GetItemInfo(Item.E_ITEM_EFFECT item_eff)
    {
        return itemInfos.Find(iteminfo => item_eff == iteminfo.effectMode);
    }

    public ItemInfo GetItemInfo(int idx)
    {
        ItemInfo itemInfo = itemInfos[idx];
        itemInfos.Remove(itemInfo);
        return itemInfo;
    }

    public void RemoveItemInfo(ItemInfo itemInfo)
    {
        itemInfos.Remove(itemInfo);
    }
    ////테스트용 코드
    //private void OnGUI()
    //{
    //    int w = 100;
    //    int h = 20;
    //    for(int i = 0;  i< itemInfos.Count; i++)
    //    {
    //        if(GUI.Button(new Rect(0,h*i,w,h), itemInfos[i].name))
    //        {
    //            ItemInfo itemInfo = GetItemInfo(i);
    //            Item.Use(itemInfo.effectMode, this.gameObject);
    //        }
    //    }
    //}

    public void TestIventory(int count)
    {
        for (int i = 0; i < count; i++)
        {
            SetInventory(Item.E_ITEM_EFFECT.SUPER);
            SetInventory(Item.E_ITEM_EFFECT.BULLET);
            SetInventory(Item.E_ITEM_EFFECT.RECOVERY);
            SetInventory(Item.E_ITEM_EFFECT.SCORE);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        TestIventory(20);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
