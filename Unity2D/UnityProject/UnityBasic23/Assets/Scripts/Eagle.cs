using System.Collections;
using System.Collections.Generic;
using UnityEngine;

class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed = 1;
    public float Site = 0.5f;
    public bool isMove = false;

    public GameObject objResponPoint;
    public GameObject objPatrolPoint;

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
        FindProcess();
    }
    void Update()
    {
        MoveProcess();
        ReturnProcess();

        if(isArrival())
        {
            if(objTarget.name == objResponPoint.name)
            {
                objTarget = objPatrolPoint;
            }
            else if (objTarget.name == objPatrolPoint.name)
            {
                objTarget = objResponPoint;
            }
        }
    }
    void ReturnProcess()
    {
        if (objTarget == null)
        {
            objTarget = objResponPoint;
        }
    }
    void FindProcess()
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
    void MoveProcess()
    {
        if (objTarget != null)
        {
            Vector3 vTaqrget = objTarget.transform.position;
            Vector3 vPos = this.transform.position;
            Vector3 vDist = vTaqrget - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            if (fDist > Time.deltaTime)
            {
                transform.position += vDir * Speed * Time.deltaTime;
                isMove = true;
            }
            else isMove = false;
        }
    }

    public bool isArrival()
    {
        return !isMove;
    }
}
