using System.Collections;
using System.Collections.Generic;
using UnityEngine;

class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed = 1;
    public float Site = 0.5f;

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, Site);
    }

    //private void FixedUpdate()
    //{
    //    Vector3 vPos = this.transform.position;
    //    Collider2D[] colliders =
    //        Physics2D.OverlapCircleAll(vPos, Site);

    //    for (int i = 0; i < colliders.Length; i++)
    //    {
    //        Collider2D collider = colliders[i];
    //        Debug.Log(i+":"+collider.name);
    //        if (collider.tag == "Player")
    //            objTarget = collider.gameObject;
    //    }
    //}

    private void FixedUpdate()
    {
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Vector3 vPos = this.transform.position;
        Collider2D collider =
            Physics2D.OverlapCircle(vPos, Site, nLayer);

        if (collider)
        {
            objTarget = collider.gameObject;
        }
    }


    // Update is called once per frame
    void Update()
    {
        if (objTarget)
        {
            Vector3 vTaqrget = objTarget.transform.position;
            Vector3 vPos = this.transform.position;
            Vector3 vDist = vTaqrget - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            if(fDist > Time.deltaTime)
                transform.position += vDir * Speed * Time.deltaTime;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(objTarget.tag == "Player")
            objTarget = collision.gameObject;
    }
}
