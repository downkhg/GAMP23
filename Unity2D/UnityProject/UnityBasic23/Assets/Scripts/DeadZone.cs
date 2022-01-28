using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeadZone : MonoBehaviour
{
    public void ResponCollision(GameObject objCollition)
    {
        Destroy(objCollition);
        GameObject prefab =
            Resources.Load("Prefabs/" + objCollition.name) as GameObject;
        GameObject obj = Instantiate(prefab);
        obj.name = objCollition.name;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Destroy(collision.gameObject);
        //ResponCollision(collision.gameObject);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(collision.gameObject);
        //ResponCollision(collision.gameObject);
    }
}
