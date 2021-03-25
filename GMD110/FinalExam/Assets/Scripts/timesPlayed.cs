using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class timesPlayed : MonoBehaviour
{
    public Text repeats;
    static int times;
    int tP;
    void Start()
    {
        
    }

    void Update()
    {
        tP = times;
        PlayerPrefs.SetInt("Times Played", tP);
    }

    public static void addTimesPlayed(int t)
    {
        times += t;
    }

    public static int getTimes()
    {
        return times;
    }
}
