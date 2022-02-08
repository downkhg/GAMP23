using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public CameraTracker cameraTracker;
    public Responner responnerPlayer;

    // Update is called once per frame
    void Update()
    {
        if(responnerPlayer.objPlayer)
        {
            cameraTracker.objTarget = responnerPlayer.objPlayer;
        }
    }
}
