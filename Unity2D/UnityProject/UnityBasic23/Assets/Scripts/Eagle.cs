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

    public enum E_AI_STATUS { TRACKING, RETURN, PATROL}
    public E_AI_STATUS curAIState;

    private void Awake()
    {
        SetAIStatus(E_AI_STATUS.RETURN);
    }

    void SetAIStatus(E_AI_STATUS state)
    {
        switch(state)
        {
            case E_AI_STATUS.TRACKING:
                break;
            case E_AI_STATUS.RETURN:
                objTarget = objResponPoint;
                break;
            case E_AI_STATUS.PATROL:
                objTarget = objPatrolPoint;
                break;
        }
        curAIState = state;
    }

    void UpdateAIStatus()
    {
        switch (curAIState)
        {
            case E_AI_STATUS.TRACKING:
                if (objTarget == null)
                    SetAIStatus(E_AI_STATUS.RETURN);
                break;
            case E_AI_STATUS.RETURN:
                if (isArrival())
                    SetAIStatus(E_AI_STATUS.PATROL);
                break;
            case E_AI_STATUS.PATROL:
                PatrolProcess();
                break;
        }
    }

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
        AttackProcess();
    }
    void AttackProcess()
    {
        CircleCollider2D circleCollider = 
            this.gameObject.GetComponent<CircleCollider2D>();
        Vector2 vPos = this.transform.position;
        Vector2 vCenter = vPos + circleCollider.offset;
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider = 
            Physics2D.OverlapCircle(vCenter, circleCollider.radius, nLayer);

        if (collider)
        {
            Player me = this.GetComponent<Player>();
            Player target = collider.gameObject.GetComponent<Player>();

            me.Attack(target);
        }
    }
    void Update()
    {
        MoveProcess();
        UpdateAIStatus();
        //ReturnProcess();
        //PatrolProcess();
    }
    void PatrolProcess()
    {
        if (isMove == false)
        {
            if (objTarget.name == objResponPoint.name)
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
            SetAIStatus(E_AI_STATUS.TRACKING);
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
