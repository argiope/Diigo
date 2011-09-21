<?php
/**
 * @file
 * the template file for the diigo bookmarks.
 *
 * @param $bookmarks
 * is an array of bookmark objects
 *
 * @param $bookmark
 *   a bookmark object it should contain the following properties:
 *    -url
 *       the url of the bookmark
 *    -title
 *       The title of the link
 *    -tags
 *       the diigo tags associated with the link
 *    -description
 *       the discription of the link
 *    -created_at
 *       date and time the link is created at
 *    -updated_at
 *       the time when the link was last revised
 *    -link
 *       the preformatted link with the title and url
 *    -favicon
 *       an image that uses gets google's cached favicons
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

