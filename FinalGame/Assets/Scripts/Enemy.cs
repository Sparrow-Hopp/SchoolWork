using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public static int health;
    int level, experience;
    void Start()
    {
        level = Random.Range(1, (GameManager.playerLevel + 2));
        health = 50 * level;
        experience = 5 * level;
    }

    // Update is called once per frame
    void Update()
    {
        if (isDead())
        {
            GameManager.addExperience(experience);
        }
    }

    public static void removeHealth(int h)
    {
        health -= h;
    }

    bool isDead()
    {
        return health <= 0;
    }
}
