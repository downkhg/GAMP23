using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int nAttack;
    public int nHP;
    public int nLv;
    public int nExp;

    public int nMaxHP;

    public GUIStatusBar guiHPBar;
    public GUIStatusBar guiExpBar;

    private void Start()
    {
        nMaxHP = nHP;
    }

    private void Update()
    {
        if (Death()) Destroy(this.gameObject);
        LvUp();

        if (guiHPBar) guiHPBar.SetStatus(nHP, nMaxHP);
        if (guiExpBar) guiExpBar.SetStatus(nExp, 100);
    }

    public void LvUp()
    {
        if(nExp >= 100)
        {
            nLv++;
            nAttack += 5;
            nHP += 5;
            nMaxHP += 5;
            nExp -= 100;
        }
    }

    public void StillExp(Player target)
    {
        nExp += target.nExp + target.nLv * 100;
    }

    public void Attack(Player target)
    {
        target.nHP -= this.nAttack;
    }
    public bool Death()
    {
        if (nHP > 0) return false;
        else return true;
    }

    public void Show()
    {
        Debug.Log("###" + this.gameObject.name + "###");
        Debug.Log("HP:" + nHP);
        Debug.Log("Atk:" + nAttack);
    }
    public int idx = 0;
    //private void OnGUI()
    //{
    //    int w = 100, h = 20;
    //    GUI.Box(new Rect(w * idx,0,w,h),"###" + this.gameObject.name + "###");
    //    GUI.Box(new Rect(w * idx, 20, w, h), "HP:" + nHP);
    //    GUI.Box(new Rect(w * idx, 40, w, h), "Atk:" + nAttack);
    //}

  
}
