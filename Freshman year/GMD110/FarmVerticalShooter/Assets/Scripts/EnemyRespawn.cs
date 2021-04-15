using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyRespawn : MonoBehaviour
{
    float respawnX, respawnY;
    public float lowBoundsX, highBoundsX, lowBoundsY, highBoundsY;
    public float wait, next;
    public GameObject enemy;
    // Start is called before the first frame update

    // Update is called once per frame
    void Update()
    {
        if (Time.time > next)//using actual time to measure how many seconds in order to spawn more enemies
        {
            respawnX = Random.Range(lowBoundsX, highBoundsX);
            respawnY = Random.Range(lowBoundsY, highBoundsY);
            Vector2 respawnPos = new Vector2(respawnX, respawnY);
            next = Time.time + wait;//increasing the time until next spawn by however much the wait time is
            Instantiate(enemy, respawnPos, Quaternion.identity);//instantiate a new enemy
        }
    }
}
