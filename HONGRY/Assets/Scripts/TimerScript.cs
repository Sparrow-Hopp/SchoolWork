using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class TimerScript : MonoBehaviour
{
    public Text timerText;
    private float startTime;
    public string sceneName;
    int timer;

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

        timer = 250 - seconds;

        timerText.text = timer.ToString();

        if (timerText.text == "0")
            SceneManager.LoadScene (sceneName);
    }

    void addTime(int add)//adds time to the timer
    {
        timer += add;
    }
}
