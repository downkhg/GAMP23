using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public float ShotPower;

    public void Shot(Vector3 dir, Player master)
    {
        GameObject copyBullet = Instantiate(objBullet);
        copyBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = copyBullet.GetComponent<Rigidbody2D>();
        Bullet bullet = copyBullet.GetComponent<Bullet>();
        bullet.master = master;
        if(rigidbody != null)
            rigidbody.AddForce(dir * ShotPower);
    }
}
