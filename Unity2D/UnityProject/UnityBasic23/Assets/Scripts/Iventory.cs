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

    public ItemInfo GetItemInfo(int idx)
    {
        ItemInfo itemInfo = itemInfos[idx];
        itemInfos.Remove(itemInfo);
        return itemInfo;
    }

    private void OnGUI()
    {
        int w = 100;
        int h = 20;
        for(int i = 0;  i< itemInfos.Count; i++)
        {
            if(GUI.Button(new Rect(0,h*i,w,h), itemInfos[i].name))
            {
                ItemInfo itemInfo = GetItemInfo(i);
                Item.Use(itemInfo.effectMode, this.gameObject);
            }
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
