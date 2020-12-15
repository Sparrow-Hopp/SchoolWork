using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class updateHealth : MonoBehaviour
{
    public GameObject GM;

    void Start()
    {
        GM = GameObject.Find("Game_Manager");
    }
    void Update()
    {
        float health = PlayerPrefs.GetFloat("curHealth");
        float maxHealth = PlayerPrefs.GetFloat("maxHealth");
        RectTransform healthRectTransform = gameObject.GetComponent<RectTransform> ();
        healthRectTransform.sizeDelta = new Vector2 (health/maxHealth*150, healthRectTransform.sizeDelta.y);
    }
}
