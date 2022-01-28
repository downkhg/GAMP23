using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float Speed = 1;
    public float JumpPower;
    public bool isGround;
    public int Score;
    public Gun gun;
    public Transform transResponPoint;

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Score:" + Score);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {   
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Speed * Time.deltaTime;

        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Speed * Time.deltaTime;

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

        if (Input.GetKeyDown(KeyCode.X))
        {
            gun.Shot();
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isGround = true;
       
        Debug.Log("OnCollisionEnter2D:"+collision.gameObject.name);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Item")
        //if (collision.gameObject.name == "cherry")
        {
            Score++;
            Destroy(collision.gameObject);
        }

        if(collision.gameObject.name == "DeadZone")
        {
            Destroy(collision.gameObject);
            GameObject prefab = Resources.Load("Prefabs/" + this.name) as GameObject;
            GameObject obj = Instantiate(prefab, transResponPoint.position, Quaternion.identity);
            obj.name = this.name;
            obj.GetComponent<Dynamic>().transResponPoint = transResponPoint;
        }
    }
}
