using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class ItemInfo
{
    public string name;
    public string comment;
    public Item.E_ITEM_EFFECT effectMode;
    public string icon;
    public string effectObject;
    public string itemObject;

    public ItemInfo(string name, string comment, Item.E_ITEM_EFFECT eff_mode, string icon, string eff_obj, string item_obj)
    {
        this.name = name;
        this.comment = comment;
        this.effectMode = eff_mode;
        this.icon = icon;
        this.effectObject = eff_obj;
        this.itemObject = item_obj;
    }
}

public class ItemManager : MonoBehaviour
{
    public List<ItemInfo> itemInfos;

    public void Initialize()
    {
        itemInfos.Add(new ItemInfo("무적","일정시간동안 데미지를 받지 않는다.",Item.E_ITEM_EFFECT.SUPER,"yellow_gen","super_mode_eff","super_mode_obj"));
        itemInfos.Add(new ItemInfo("체리", "체력을 모두 회복한다.", Item.E_ITEM_EFFECT.RECOVERY, "cherry", "eat_eff", "recover_cherry_obj"));
        itemInfos.Add(new ItemInfo("보석", "점수를 100점 획득한다.", Item.E_ITEM_EFFECT.SCORE, "white_gem", "eat_eff", "white_gem_obj"));
        itemInfos.Add(new ItemInfo("총알", "총알을 1개씩 발사한다.", Item.E_ITEM_EFFECT.BULLET, "bullet", "hit_bullet", "bullet_obj"));
    }

    private void Awake()
    {
        Initialize();
    }
}
