using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class TimerScript : MonoBehaviour
{

    public Text timerText;
    private float startTime;
    public int time;
    public GameObject enemy;

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

        int timer = seconds;

        timerText.text = timer.ToString();//always goes up

    }
}
