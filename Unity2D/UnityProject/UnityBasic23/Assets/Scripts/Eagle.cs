using System.Collections;
using System.Collections.Generic;
using UnityEngine;

class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed = 1;
    
    // Start is called before the first frame update
    void Start()
    {
        
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
