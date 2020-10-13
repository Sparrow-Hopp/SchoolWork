using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class EnemyTrigger : MonoBehaviour
{
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "Enemy")
        {
            col.gameObject.GetComponent<Enemy>().Respawn();
        }
    }
}