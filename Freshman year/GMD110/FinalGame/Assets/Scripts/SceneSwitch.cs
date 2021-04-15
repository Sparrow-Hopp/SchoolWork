using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneSwitch : MonoBehaviour
{
    GameObject GM;
    public string sceneName;
    void Start()
    {
        GM = GameObject.Find("Game_Manager");
    }
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Destroy(GM);
            SceneManager.LoadScene(sceneName);
        }
    }
}
