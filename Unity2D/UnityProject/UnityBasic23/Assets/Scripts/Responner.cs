using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public string prefabName;
    public bool isRespon;
    public float time;
    IEnumerator ProcessTime(float time)
    {
        isRespon = true;
        yield return new WaitForSeconds(time);
        objPlayer = ResponObject();
        isRespon = false;
    }

    public GameObject ResponObject()
    {
        GameObject prefab =
            Resources.Load("Prefabs/" + prefabName) as GameObject;
        GameObject obj = 
            Instantiate(prefab, this.transform.position, Quaternion.identity);
        obj.name = prefabName;
        return obj;
    }

    // Start is called before the first frame update
    void Start()
    {
        prefabName = objPlayer.name;
    }

    // Update is called once per frame
    void Update()
    {
        if(objPlayer == null)
        {
            if (isRespon == false)
            {
                //objPlayer = ResponObject();
                StartCoroutine(ProcessTime(time));
            }
        }
        //else //독수리에게만 필요한 코드이므로 리스폰에 있는것은 부적절하다. 
        //{
        //    Eagle eagle = objPlayer.GetComponent<Eagle>();
        //    if(eagle)
        //        eagle.objResponPoint = this.gameObject;
        //}
    }
}
