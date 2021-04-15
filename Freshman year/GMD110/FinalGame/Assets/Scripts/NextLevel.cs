using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NextLevel : MonoBehaviour
{
    public string sceneName;
    public int levelReq;
    void Update()
    {
        if (GameManager.playerLevel == levelReq)
        {
            SceneManager.LoadScene(sceneName);
        }
    }
}
