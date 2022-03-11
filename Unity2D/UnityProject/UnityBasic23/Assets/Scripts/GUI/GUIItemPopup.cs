using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemPopup : MonoBehaviour
{
    public Text textName;
    public Text textComment;

    public void Set(ItemInfo itemInfo)
    {
        textName.text = itemInfo.name;
        textComment.text = itemInfo.comment;
    }

    // Start is called before the first frame update
    void Start()
    {
        ItemInfo itemInfo = GameManager.GetInstance().itemManager.GetItemInfo(Item.E_ITEM_EFFECT.BULLET);

        Set(itemInfo);
    }

    // Update is called once per frame
    void Update()
    {
        if(gameObject.activeSelf)
        {
            RectTransform rectTr = GetComponent<RectTransform>();
            rectTr.position = Input.mousePosition;
        }
    }
}
