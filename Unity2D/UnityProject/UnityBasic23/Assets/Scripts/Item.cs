using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public enum E_ITEM_EFFECT { SUPER, RECOVERY, SCORE, BULLET }
    public E_ITEM_EFFECT eEffect;

    public static bool Use(E_ITEM_EFFECT eff, GameObject targetObject)
    {
        switch (eff)
        {
            case E_ITEM_EFFECT.SUPER:
                SuperMode superMode = targetObject.GetComponent<SuperMode>();
                if (superMode != null)
                    superMode.Active();
                return true;
                break;
            case E_ITEM_EFFECT.RECOVERY:
                Player player = targetObject.GetComponent<Player>();
                if (player)
                    player.nHP = player.nMaxHP;
                return true;
                break;
            case E_ITEM_EFFECT.SCORE:
                Dynamic dynamic = targetObject.GetComponent<Dynamic>();
                if (dynamic)
                    dynamic.Score += 100;
                return true;
                break;
            case E_ITEM_EFFECT.BULLET:
                return true;
                break;
        }
        return false;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Player")
        {
            Iventory iventory = collision.gameObject.GetComponent<Iventory>();
            //Use(eEffect, collision.gameObject);
            iventory.SetInventory(this);
            Destroy(gameObject);
        }
    }
}