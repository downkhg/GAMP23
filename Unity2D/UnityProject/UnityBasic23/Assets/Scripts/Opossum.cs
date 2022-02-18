using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Opossum : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position += Vector3.left * Time.deltaTime;
    }

    private void FixedUpdate()
    {
        BoxCollider2D boxCollider = GetComponent<BoxCollider2D>();
        Vector2 vPos = transform.position;
        Vector2 vCenter = vPos + boxCollider.offset;
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider = Physics2D.OverlapBox(vCenter, boxCollider.size, 0, nLayer);
        if(collider)
        {
            SuperMode superMode = collider.GetComponent<SuperMode>();

            if (superMode != null && superMode.isUse == false)
            {
                Player me = this.GetComponent<Player>();
                Player target = collider.gameObject.GetComponent<Player>();

                me.Attack(target);
                superMode.Active();
            }
        }
    }
}
