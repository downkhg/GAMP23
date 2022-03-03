using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public enum E_ITEM_EFFECT { SUPER, RECOVERY, SCORE, BULLET }
    public E_ITEM_EFFECT eEffect;

    public void Use(GameObject obj)
    {
        switch (eEffect)
        {
            case E_ITEM_EFFECT.SUPER:
                SuperMode superMode = obj.GetComponent<SuperMode>();
                if(superMode != null)
                    superMode.Active();
                break;
            case E_ITEM_EFFECT.RECOVERY:
                Player player = obj.GetComponent<Player>();
                if(player)
                    player.nHP = player.nMaxHP;
                break;
            case E_ITEM_EFFECT.SCORE:
                Dynamic dynamic = obj.GetComponent<Dynamic>();
                if (dynamic)
                    dynamic.Score += 100;
                break;
            case E_ITEM_EFFECT.BULLET:
                break;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Use(collision.gameObject);
    }
}