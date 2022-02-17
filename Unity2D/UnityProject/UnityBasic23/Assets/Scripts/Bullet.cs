using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public Vector3 vStartPos;
    public float Dist;
    public Player master;

    private void Start()
    {
        //설정한 힘에 따라 사거리가 달라진다.
        //Destroy(this.gameObject, 1);
        vStartPos = this.transform.position;
    }

    private void Update()
    {
        Vector3 vPos = this.transform.position;
        float fDist = Vector3.Distance(vStartPos, vPos);

        if (fDist > Dist)
            Destroy(this.gameObject);
    }


    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Monster")
        {
            //Destroy(collision.gameObject);
            //Player player = GameObject.Find("player").GetComponent<Player>();
            //Player player = 
            //    GameManager.GetInstance().responnerPlayer.objPlayer.GetComponent<Player>();
            Player player = master;
            Player target = collision.gameObject.GetComponent<Player>();

            player.Attack(target);
            Destroy(this.gameObject);
        }
    }
}
