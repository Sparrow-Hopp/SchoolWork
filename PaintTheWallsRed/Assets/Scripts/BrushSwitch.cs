using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BrushSwitch : MonoBehaviour
{
    int counter;
    public GameObject [] brushes;
    void Start()
    {
        brushes = GameObject.FindGameObjectsWithTag("Brush");
        counter = 0;
        for (int i = 1; i < brushes.Length; i++)
            brushes[i].SetActive(false);
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(1))//switch which brush you're using
        {
            counter++;
            brushes[counter-1].SetActive(false);
            counter%=brushes.Length;
            brushes[counter].SetActive(true);
        }
    }
}
