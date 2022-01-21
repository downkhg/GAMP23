using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public int Score;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.name == "player")
        {
            Dynamic dynamic = collision.gameObject.GetComponent<Dynamic>();
            dynamic.Score += Score;
            Destroy(this.gameObject);
        }
    }
}
