<?php
/**
 * @file
 * the template file for the diigo bookmarks.
 *
 * @param $bookmarks
 * is an array of bookmark objects
 *
 * @param $bookmark
 * a bookmark object it should contain the following properties:
 *
 * @param $bookmark->url
 * the url of the bookmark
 *
 * @param $bookmark->title
 *
 * @param $bookmark->tags
 *
 * @param $bookmark->desc
 *
 * @param $bookmark->created_at
 *
 * @param $bookmark->updated_at
 *
 */
?>
<ul>
  <?php foreach($bookmarks as $bookmark):?>
    <li>
      <?php //dpr($bookmark); ?>
      <div>
        <?php print $bookmark->favicon; ?>
        <?php print $bookmark->link; ?>
      </div>
      <?php if($bookmark->description): ?>
        <div>
          <?php print $bookmark->description; ?>
        </div>
      <?php endif; ?>
      <?php if($bookmark->tags): ?>
        <div>
          <?php foreach($bookmark->tags as $tag): ?>
            <span><?php print $tag; ?></span>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>
      <div>
        <?php print $bookmark->created_at; ?>
      </div>
      <?php if($bookmark->updated_at): ?>
        <div>
          <?php print $bookmark->updated_at; ?>
        </div>
      <?php endif; ?>
    </li>
  <?php endforeach; ?>
</ul>

