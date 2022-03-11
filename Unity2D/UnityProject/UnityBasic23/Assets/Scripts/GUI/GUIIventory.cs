using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIIventory : MonoBehaviour
{
    public List<GUIItemButton> listItemButton;
    public GridLayoutGroup gridConttent;

    public void SetIventory(Iventory iventory)
    {
        GameObject prefabItemButon = Resources.Load("GUI/ItemButton") as GameObject;
        foreach(ItemInfo ItemInfo in iventory.itemInfos)
        {
            GameObject objItemButton = Instantiate(prefabItemButon,gridConttent.transform);
            GUIItemButton guiItemButton = objItemButton.GetComponent<GUIItemButton>();
            guiItemButton.Set(ItemInfo);
            listItemButton.Add(guiItemButton);
        }
        SetContentSize();
    }

    public void RemoveButtons()
    {
        foreach (GUIItemButton guiItemButton in listItemButton)
        {
            Destroy(guiItemButton.gameObject);
        }
        listItemButton.Clear();
    }

    public void SetContentSize()
    {
        RectTransform rectContent = gridConttent.gameObject.GetComponent<RectTransform>();
        float width = gridConttent.cellSize.x + gridConttent.spacing.x;
        float hight = gridConttent.cellSize.y + gridConttent.spacing.y;
        Vector2 vCotentSize = rectContent.sizeDelta;
        Vector2 vCotentCountSize = vCotentSize - new Vector2(gridConttent.padding.left, gridConttent.padding.top);
        int nCol = (int)(vCotentSize.x / width);
        int nRow = listItemButton.Count / nCol;
        if (listItemButton.Count % nCol > 0) nRow++;
        Debug.Log(string.Format("CotentResize:WxH({0}x{1}),CxR({2}x{3})",width,hight,nCol,nRow));
        vCotentSize.y = nRow * hight + gridConttent.padding.top;
        rectContent.sizeDelta = vCotentSize;
    }

    //void Start()//테스트용
    //{
    //    Debug.Log(gameObject.name + " Start");
    //    GameObject objPlayer = GameManager.GetInstance().responnerPlayer.objPlayer;

    //    if (objPlayer)
    //    {
    //        Iventory iventory = objPlayer.GetComponent<Iventory>();
    //        SetIventory(iventory);
    //    }
    //}
}
