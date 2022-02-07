using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    
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
                transform.position += vDir * Time.deltaTime;
        }
    }
}
