using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public float ShotPower;

    public void Shot(Vector3 dir)
    {
        GameObject copyBullet = Instantiate(objBullet);
        copyBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = copyBullet.GetComponent<Rigidbody2D>();
        if(rigidbody != null)
            rigidbody.AddForce(dir * ShotPower);
    }
}
