using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class TimerScript2 : MonoBehaviour
{

    public Text timerText;
    private float startTime;
    public string sceneName;

    // Start is called before the first frame update
    void Start()
    {
       startTime = Time.time; 
    }

    // Update is called once per frame
    void Update()
    {
        float t = Time.time - startTime;

        int seconds = (int)t;

        int timer = 300 - seconds;

        timerText.text = timer.ToString();

        if (timerText.text == "0")
            SceneManager.LoadScene (sceneName);
    }
}
