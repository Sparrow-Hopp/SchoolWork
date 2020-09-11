using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ReverseScript : MonoBehaviour
{
    public string sceneName; 

    // Update is called once per frame
    void Update()
    {
        CheckStart();
    }

    void CheckStart()
    {
        if (Input.GetMouseButtonDown (1)) 
        {
            //Change the scene name depending on which script you are on.
            //Note that this will require that each SceneManager has a string
            //typed into the Unity Inspector for sceneName.
            SceneManager.LoadScene (sceneName);
        }
    }
}