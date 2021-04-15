using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class LoadScene : MonoBehaviour
{
    public string sceneName;

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
            SceneManager.LoadScene (sceneName);
    }
}
