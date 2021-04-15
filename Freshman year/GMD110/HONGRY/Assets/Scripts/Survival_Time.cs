using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Survival_Time : MonoBehaviour
{
    public Text timerText;
    int seconds;

    void Start()
    {
        seconds = PlayerPrefs.GetInt("Time Survived");
        timerText.text = seconds.ToString();
    }
}
