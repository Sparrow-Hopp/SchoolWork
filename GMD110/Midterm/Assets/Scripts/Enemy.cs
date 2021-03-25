using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Enemy : MonoBehaviour
{
    float respawnX, respawnY;
    public float lowBoundsX, highBoundsX, lowBoundsY, highBoundsY, lowScale, highScale;
    // Start is called before the first frame update
    public void Respawn()
    {
        gameObject.SetActive(true);
        respawnX = Random.Range(lowBoundsX, highBoundsX);
        respawnY = Random.Range(lowBoundsY, highBoundsY);
        Vector2 newPos = new Vector2(respawnX, respawnY);
        Vector2 newScale = new Vector2 (Random.Range(lowScale, highScale), Random.Range(lowScale, highScale));
        transform.localScale = newScale;
        transform.position = newPos;
        GetComponent<Rigidbody2D>().velocity = Vector2.zero;
    }
    void OnMouseDown()
    {
        Debug.Log("down");
        gameObject.SetActive(false); //set SetActive to false (deactivating enemies)
        GameManager.singleton.UnlistEnemy(gameObject); //remove enemy reference from activeEnemyList (that lives in the singleton GameManager object)
    }    
}