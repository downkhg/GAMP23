using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower;
    public bool isGround;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {   
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Time.deltaTime;
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Time.deltaTime;
        //if (Input.GetKey(KeyCode.Space))
        //    transform.position += Vector3.up * 3 * Time.deltaTime;
        //스페이스키를 눌렀을때 점프
        //점프: 위로 힘을 가해서 올라가다 떨어지는것
        //발판이있어야 점프가 가능하다 -> 땅에 서있을때 점프가 가능하다.
        //점프중일때는 점프가 되지않아야한다.
        if(Input.GetKeyDown(KeyCode.Space))
        {
            if (isGround == true)
            {
                Rigidbody2D rigidbody = GetComponent<Rigidbody2D>();
                rigidbody.AddForce(Vector3.up * JumpPower);
                isGround = false;
            }
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isGround = true;
        Debug.Log("OnCollisionEnter2D:"+collision.gameObject.name);
    }
}
