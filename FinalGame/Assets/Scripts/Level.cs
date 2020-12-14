using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Level : MonoBehaviour
{
    public Text level;

    void Start()
    {
        level.text = GameManager.playerLevel.ToString();
    }
}
